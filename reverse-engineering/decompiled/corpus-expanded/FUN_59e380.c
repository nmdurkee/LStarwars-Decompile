/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e380; label: FUN_0059e380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059e380(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_00956430 < 0x20) {
    uVar2 = FUN_004f9e70(param_1);
    iVar1 = DAT_00956430 + DAT_0095634c * 0x38;
    DAT_00956430 = DAT_00956430 + 1;
    *(undefined2 *)(DAT_009562f8 + 0x20 + iVar1 * 2) = uVar2;
  }
  return;
}

