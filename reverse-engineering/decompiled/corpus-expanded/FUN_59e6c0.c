/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e6c0; label: FUN_0059e6c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059e6c0(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  if (DAT_0095642c < 0x10) {
    iVar2 = FUN_004f9e70(param_1);
    if (iVar2 < 0) {
      FUN_004f9e70(param_1);
      FUN_0059e3d0(iVar2);
      return;
    }
    (&DAT_009563d0)[DAT_0095642c] = iVar2;
    uVar1 = FUN_004f9e70(param_1);
    (&DAT_009562e8)[DAT_0095642c] = uVar1;
    DAT_0095642c = DAT_0095642c + 1;
  }
  return;
}

