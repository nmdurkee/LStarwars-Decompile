/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x646f70; label: FUN_00646f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00646f70(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = DAT_02920970;
  if (DAT_02920970 != 0) {
    iVar1 = *(int *)(param_2 + 0xc);
    if (iVar1 == 0) {
      uVar3 = FUN_006e6b90();
      *(undefined4 *)(iVar2 + 0x108) = uVar3;
      return;
    }
    if (iVar1 == 1) {
      uVar3 = FUN_006e6b90();
      *(undefined4 *)(iVar2 + 0x10c) = uVar3;
      return;
    }
    if (iVar1 == 2) {
      uVar3 = FUN_006e6b90();
      *(undefined4 *)(iVar2 + 0x110) = uVar3;
    }
  }
  return;
}

