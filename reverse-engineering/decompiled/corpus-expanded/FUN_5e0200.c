/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0200; label: FUN_005e0200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0200(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *in_EAX;
  undefined4 uVar3;
  int *unaff_EDI;
  
  uVar3 = FUN_00603530();
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar3 = FUN_00603580(uVar3,param_2,*(undefined4 *)(*(int *)(*in_EAX + 0x50) + in_EAX[1] * 4),uVar1
                       ,*param_3);
  *param_3 = uVar3;
  *(undefined1 *)in_EAX[9] = 0x8c;
  *(undefined1 *)(in_EAX[9] + 1) = 3;
  *(undefined4 *)(in_EAX[9] + 4) = uVar3;
  in_EAX[9] = in_EAX[9] + 0x10;
  *unaff_EDI = in_EAX[9] + -0x10;
  *(undefined1 *)in_EAX[9] = 0x82;
  *(undefined1 *)(in_EAX[9] + 1) = 3;
  *(undefined4 *)(in_EAX[9] + 4) = uVar1;
  in_EAX[9] = in_EAX[9] + 0x10;
  iVar2 = in_EAX[9];
  unaff_EDI[1] = iVar2 + -0x10;
  FUN_00603ad0(*unaff_EDI,iVar2 + -0x10,param_4);
  FUN_00603b10(*unaff_EDI,unaff_EDI[1],param_5);
  return;
}

