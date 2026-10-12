import fs from 'node:fs/promises';
import path from 'node:path';
import {createHash} from 'node:crypto';
import {pathToFileURL} from 'node:url';

// MkDat v4 / type -3 as observed in this PC installation.
// Format cross-check: https://aluigi.altervista.org/bms/ttgames.bms
export function nameHash(name) {
  let hash = 0x811c9dc5;
  for (const c of name.toUpperCase().replaceAll('/', '\\')) hash = Math.imul(hash ^ c.charCodeAt(0), 0x199933) >>> 0;
  return hash;
}
export async function readExactly(handle, size, offset) {
  if (!Number.isSafeInteger(size) || size < 0 || size > 128 * 1024 * 1024) throw Error('Invalid read size');
  const buffer = Buffer.alloc(size);
  let done = 0;
  while (done < size) {
    const {bytesRead} = await handle.read(buffer, done, size - done, offset + done);
    if (!bytesRead) throw Error('Unexpected end of file');
    done += bytesRead;
  }
  return buffer;
}
export function parseIndex(index, archiveSize, indexOffset) {
  if (index.length < 16 || index.readInt32LE(0) !== -3) throw Error('Only the observed MkDat type -3 is supported');
  const count = index.readUInt32LE(4);
  const nodesOffset = 8 + count * 16;
  if (nodesOffset + 4 > index.length) throw Error('File table exceeds index');
  const nodeCount = index.readUInt32LE(nodesOffset);
  const poolSizeOffset = nodesOffset + 4 + nodeCount * 8;
  if (poolSizeOffset + 4 > index.length) throw Error('Name table exceeds index');
  const poolOffset = poolSizeOffset + 4;
  const poolSize = index.readUInt32LE(poolSizeOffset);
  const hashesOffset = poolOffset + poolSize;
  if (hashesOffset + count * 4 + 8 > index.length) throw Error('Hash table exceeds index');
  const hashToRecord = new Map();
  const entries = [];
  for (let i = 0; i < count; i++) {
    const p = 8 + i * 16;
    const flags = index.readUInt32LE(p + 12);
    const entry = {id:i, hash:index.readUInt32LE(hashesOffset + i * 4), offset:index.readUInt32LE(p) * 256 + (flags >>> 24), storedSize:index.readUInt32LE(p+4), size:index.readUInt32LE(p+8), flags:flags & 0xffffff};
    if (entry.offset < 8 || entry.offset + entry.storedSize > indexOffset || entry.offset + entry.storedSize > archiveSize) throw Error('Payload outside archive: ' + i);
    if (hashToRecord.has(entry.hash)) throw Error('Ambiguous path hash: ' + entry.hash);
    hashToRecord.set(entry.hash, entry);
    entries.push(entry);
  }
  const parents = [];
  let current = '';
  let leafCount = 0;
  for (let i = 0; i < nodeCount; i++) {
    const p = nodesOffset + 4 + i * 8;
    const next = index.readInt16LE(p), previous = index.readInt16LE(p+2), nameOffset = index.readInt32LE(p+4);
    if (previous < 0 || previous >= i && previous !== 0) throw Error('Invalid previous-node link');
    if (previous !== 0) current = parents[previous];
    parents[i] = current;
    let name = '';
    if (nameOffset >= 0) {
      if (nameOffset >= poolSize) throw Error('Invalid name offset');
      const end = index.indexOf(0, poolOffset + nameOffset);
      if (end < 0 || end >= hashesOffset) throw Error('Unterminated name');
      name = index.toString('latin1', poolOffset + nameOffset, end);
    }
    if (next > 0) { if (name) current += name + '/'; continue; }
    const fullPath = current + name;
    if (!fullPath || fullPath.split('/').some(s => !s || s === '.' || s === '..' || /[\\:]/.test(s))) throw Error('Unsafe archive path');
    const record = hashToRecord.get(nameHash(fullPath));
    if (!record || record.path) throw Error('Unresolved or duplicate path: ' + fullPath);
    record.path = fullPath;
    record.nameNode = i;
    leafCount++;
  }
  if (leafCount !== count || entries.some(e => !e.path)) throw Error('Incomplete path resolution');
  return {format:'MkDat v4 / index type -3', count, nodeCount, indexOffset, indexSize:index.length, indexSha256:createHash('sha256').update(index).digest('hex'), entries};
}
export async function readArchive(filename) {
  const h = await fs.open(filename, 'r');
  try {
    const size = (await h.stat()).size;
    const header = await readExactly(h, 64, 0);
    if (!header.toString('latin1').includes('MkDat v4.0')) throw Error('Unexpected archive producer');
    const offset = header.readUInt32LE(0), length = header.readUInt32LE(4);
    if (offset + length !== size) throw Error('Index does not end at EOF');
    const result = parseIndex(await readExactly(h, length, offset), size, offset);
    return {archive:path.basename(filename), archiveSize:size, ...result};
  } finally { await h.close(); }
}
if (globalThis.process?.argv?.[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) {
  const [file, output] = process.argv.slice(2);
  if (!file) throw Error('Usage: node ttdat.mjs ARCHIVE.DAT [index.json]');
  const result = await readArchive(file);
  if (output) await fs.writeFile(output, JSON.stringify(result, null, 2));
  else console.log(JSON.stringify(result, null, 2));
}
