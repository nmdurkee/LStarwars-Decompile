import fs from 'node:fs';
import path from 'node:path';
import { pathToFileURL } from 'node:url';
import crypto from 'node:crypto';

// Outer GIZ container only; payload schemas are intentionally left opaque.
export function inspectGiz(buffer) {
  if (buffer.length < 8) throw new Error('Truncated GIZ header');
  const headerWord = buffer.readUInt32LE(0);
  if (headerWord !== 1) throw new Error(`Unsupported GIZ header word ${headerWord}`);
  let offset = 4;
  const chunks = [];
  let terminated = false;
  while (offset + 4 <= buffer.length) {
    const headerOffset = offset;
    const nameLength = buffer.readUInt32LE(offset);
    offset += 4;
    if (nameLength === 0) { terminated = true; break; }
    if (nameLength > 256 || offset + nameLength + 4 > buffer.length) throw new Error(`Invalid chunk name length at ${headerOffset}`);
    const nameBytes = buffer.subarray(offset, offset + nameLength);
    if ([...nameBytes].some(x => x < 32 || x > 126)) throw new Error(`Non-ASCII chunk name at ${headerOffset}`);
    const name = nameBytes.toString('ascii');
    offset += nameLength;
    const payloadSize = buffer.readUInt32LE(offset);
    offset += 4;
    if (offset + payloadSize > buffer.length) throw new Error(`Truncated payload for ${name}`);
    chunks.push({headerOffset, name, payloadOffset: offset, payloadSize});
    offset += payloadSize;
  }
  if (!terminated) throw new Error('Missing zero-name terminator');
  if (offset !== buffer.length) throw new Error(`Unexpected ${buffer.length-offset} trailing bytes`);
  return {headerWord, bytes: buffer.length, chunks, consumedBytes: offset, complete: true};
}

if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) {
  if (!process.argv[2]) { console.error('Usage: node inspect-giz.mjs <input.GIZ>'); process.exitCode = 2; }
  else { try { const file=path.resolve(process.argv[2]);const buffer=fs.readFileSync(file);console.log(JSON.stringify({path:file,sha256:crypto.createHash('sha256').update(buffer).digest('hex'),...inspectGiz(buffer)},null,2)); } catch(error) { console.error(error.message); process.exitCode=1; } }
}
