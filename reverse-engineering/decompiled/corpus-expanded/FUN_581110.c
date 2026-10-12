/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x581110; label: FUN_00581110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00581110(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int *in_EAX;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  
  if ((in_EAX[0x3c] & 0x200U) == 0) {
    uVar3 = 3;
  }
  else {
    unaff_EDI = unaff_EDI + 0xc;
    uVar3 = 1;
  }
  iVar2 = FUN_00569c70(in_EAX[1],unaff_EDI,uVar3,param_3,param_1,param_2);
  if (iVar2 == 0) {
    return 0;
  }
  (**(code **)(PTR_PTR_008040bc + 0xc))();
  if (in_EAX[1] != 0) {
    FUN_0054a850(**(undefined4 **)(in_EAX[1] + 0xca4),0x3f19999a,0);
  }
  *(undefined1 *)(in_EAX + 0x40) = 0;
  if ((*in_EAX != 0) && (pcVar1 = *(code **)(*in_EAX + 0x4c), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
  }
  if (*(short *)(*in_EAX + 0x66) != -1) {
    FUN_005478a0((int)*(short *)(*in_EAX + 0x66));
    return 1;
  }
  FUN_00547930(0x28,in_EAX + 0x22,0,0);
  return 1;
}

