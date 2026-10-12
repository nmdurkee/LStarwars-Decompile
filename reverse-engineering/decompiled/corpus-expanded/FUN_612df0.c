/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612df0; label: FUN_00612df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612df0(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0xd838);
  while ((*piVar2 == 0 || (*piVar2 != param_2))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 5;
    if (7 < iVar1) {
      return;
    }
  }
  iVar1 = in_ECX + 0xd838 + iVar1 * 0x14;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  return;
}

