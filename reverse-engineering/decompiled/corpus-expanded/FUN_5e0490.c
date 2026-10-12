/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0490; label: FUN_005e0490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0490(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *in_EAX;
  undefined4 uVar2;
  undefined4 uVar3;
  int *unaff_EDI;
  
  uVar2 = FUN_00603530();
  uVar3 = FUN_00603610(uVar2,param_2,*(undefined4 *)(*(int *)(*in_EAX + 0x50) + in_EAX[1] * 4),
                       *(undefined4 *)(param_1 + 4));
  *(undefined1 *)in_EAX[9] = 0x90;
  *(undefined1 *)(in_EAX[9] + 1) = 3;
  *(undefined4 *)(in_EAX[9] + 4) = uVar3;
  in_EAX[9] = in_EAX[9] + 0x10;
  *unaff_EDI = in_EAX[9] + -0x10;
  uVar2 = FUN_00603970(uVar2,*(undefined4 *)(param_1 + 4),param_2);
  *(undefined1 *)in_EAX[9] = 0x8f;
  *(undefined1 *)(in_EAX[9] + 1) = 3;
  *(undefined4 *)(in_EAX[9] + 4) = uVar2;
  in_EAX[9] = in_EAX[9] + 0x10;
  iVar1 = in_EAX[9];
  unaff_EDI[1] = iVar1 + -0x10;
  FUN_00603ad0(*unaff_EDI,iVar1 + -0x10,param_3);
  return;
}

