/* Ghidra pseudocode, not original source.
 * ev_291f832bd6f6d010a6248a6acee690ff87721c4cdff92148d1e7c4ba042507e6
 * Entry: 0x4fe9f0; label: FUN_004fe9f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fe9f0(undefined4 param_1)

{
  uint uVar1;
  
  if (DAT_00921200 != 0) {
    uVar1 = DAT_00921200;
    if ((DAT_00921200 & 2) != 0) {
      uVar1 = FUN_004fe640(param_1);
    }
    if ((uVar1 & 1) != 0) {
      FUN_004fe640();
      return;
    }
  }
  return;
}

