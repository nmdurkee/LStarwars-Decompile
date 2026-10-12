/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f0b0; label: FUN_0061f0b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061f0b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_1 != 0) && (iVar1 = *(int *)(param_1 + 8), iVar1 != 0)) &&
      ((*(byte *)(iVar1 + 0x11) & 2) == 0)) && (*(int *)(iVar1 + 0x3c) != 0)) {
    uVar2 = (**(code **)(iVar1 + 0x3c))(param_1,iVar1,param_2,param_3);
    return uVar2;
  }
  return 0;
}

