/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51e8c0; label: FUN_0051e8c0
 */

void FUN_0051e8c0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(param_2 + 0x1b8);
  uVar2 = *(undefined4 *)(param_2 + 0x1bc);
  uVar3 = *(undefined4 *)(param_2 + 0x1b4);
  FUN_0051d7b0(param_1,param_2,param_3,param_4);
  *(undefined4 *)(param_2 + 0x1b4) = uVar3;
  *(undefined4 *)(param_2 + 0x1b8) = uVar1;
  *(undefined4 *)(param_2 + 0x1bc) = uVar2;
  return;
}

