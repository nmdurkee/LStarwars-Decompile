/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd480; label: FUN_004dd480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dd480(void)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = DAT_00882a6c;
  *(undefined4 *)(DAT_00882a6c + 0xb004) = 0;
  _memset((void *)(iVar2 + 0xa600),0,0xa00);
  pbVar1 = (byte *)(iVar2 + 0xb020);
  *pbVar1 = *pbVar1 & 0xfc;
  DAT_00881cc4 = 0xffffffff;
  _DAT_007ffd68 = 0xffffffff;
  _DAT_007ffd6c = 0xffffffff;
  _DAT_007ffd70 = 0xffffffff;
  _DAT_007ffd74 = 0xffffffff;
  DAT_007ffd78 = 0xffffffff;
  _DAT_007ffd7c = 0xffffffff;
  DAT_007ffd80 = 0xffffffff;
  _DAT_007ffd84 = 0xffffffff;
  return;
}

