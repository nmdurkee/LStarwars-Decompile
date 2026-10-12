/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0390; label: FUN_005e0390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0390(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int *in_EAX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *unaff_EDI;
  undefined4 local_4;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  uVar2 = FUN_00603530();
  uVar4 = *(undefined4 *)(param_1 + 4);
  uVar3 = FUN_00603580(uVar2,param_2,*(undefined4 *)(*(int *)(*in_EAX + 0x50) + in_EAX[1] * 4),uVar4
                       ,*param_3);
  *param_3 = uVar3;
  *(undefined1 *)in_EAX[9] = 0x8c;
  *(undefined1 *)(in_EAX[9] + 1) = 3;
  *(undefined4 *)(in_EAX[9] + 4) = uVar3;
  in_EAX[9] = in_EAX[9] + 0x10;
  *unaff_EDI = in_EAX[9] + -0x10;
  uVar4 = FUN_00603710(uVar2,param_4,param_5,uVar4,&local_4,unaff_EDI + 2);
  *(undefined1 *)in_EAX[9] = 0x99;
  *(undefined1 *)(in_EAX[9] + 1) = 3;
  *(undefined4 *)(in_EAX[9] + 4) = uVar4;
  in_EAX[9] = in_EAX[9] + 0x10;
  unaff_EDI[1] = in_EAX[9] + -0x10;
  *(undefined1 *)in_EAX[9] = 0x98;
  *(undefined1 *)(in_EAX[9] + 1) = 3;
  *(undefined4 *)(in_EAX[9] + 4) = local_4;
  in_EAX[9] = in_EAX[9] + 0x10;
  iVar1 = in_EAX[9];
  unaff_EDI[1] = iVar1 + -0x10;
  FUN_00603ad0(*unaff_EDI,iVar1 + -0x10,0x3f800000);
  FUN_00603b10(*unaff_EDI,unaff_EDI[1],param_6);
  return;
}

