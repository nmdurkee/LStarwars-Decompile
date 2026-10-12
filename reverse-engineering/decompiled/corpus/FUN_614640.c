/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x614640; label: FUN_00614640
 */

undefined4 FUN_00614640(int *param_1)

{
  float *pfVar1;
  float fVar2;
  int in_ECX;
  int unaff_EBP;
  int *piVar3;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  int in_stack_00000014;
  int iVar4;
  char cVar5;
  undefined4 uStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  piVar3 = (int *)(*(int *)(in_stack_00000014 + 8) + 3U & 0xfffffffc);
  *(int **)(in_stack_00000014 + 8) = piVar3 + 7;
  uStack_c = CONCAT13(*(byte *)(in_ECX + 0xe) >> 3,(undefined3)uStack_c) & 0x1ffffff;
  FUN_00617a00();
  iVar4 = (int)&uStack_c + 3;
  (**(code **)(*param_1 + 8))(iVar4,1,1);
  cVar5 = (char)((uint)iVar4 >> 0x18);
  if ((char)((uint)unaff_EDI >> 0x18) != '\0') {
    *piVar3 = 0;
  }
  piVar3[1] = piVar3[2];
  pfVar1 = (float *)(piVar3 + 3);
  piVar3[2] = (int)*pfVar1;
  if (param_1[2] == 2) {
    iStack_8 = FUN_00617a00();
    fVar2 = (float)iStack_8;
    if (iStack_8 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    *pfVar1 = fVar2;
  }
  (**(code **)(*param_1 + 8))(pfVar1,4,1);
  if (param_1[2] == 1) {
    FUN_00617a00();
    *pfVar1 = (float)(*(int *)(unaff_EBP + 0x29c) + (int)(longlong)ROUND(*pfVar1));
  }
  if (*pfVar1 < (float)piVar3[2] == (*pfVar1 == (float)piVar3[2])) {
    if (*piVar3 < 3) goto LAB_0061472c;
  }
  else {
    *piVar3 = 0;
LAB_0061472c:
    *piVar3 = *piVar3 + 1;
    if (*piVar3 < 3) goto LAB_0061476f;
  }
  piVar3[4] = (int)(1.0 / (((float)piVar3[1] - (float)piVar3[2]) * ((float)piVar3[1] - *pfVar1)));
  piVar3[5] = (int)(1.0 / (((float)piVar3[2] - *pfVar1) * ((float)piVar3[2] - (float)piVar3[1])));
  piVar3[6] = (int)(1.0 / ((*pfVar1 - (float)piVar3[1]) * (*pfVar1 - (float)piVar3[2])));
LAB_0061476f:
  FUN_00613890(param_1,unaff_EBP,uStack_c,iStack_8,uStack_4,piVar3,unaff_retaddr);
  if (cVar5 != '\0') {
    *(ushort *)(in_ECX + 0xe) = *(ushort *)(in_ECX + 0xe) & 0xfff7;
  }
  return 1;
}

