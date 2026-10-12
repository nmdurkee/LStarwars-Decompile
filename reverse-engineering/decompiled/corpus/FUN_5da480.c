/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5da480; label: FUN_005da480
 */

bool FUN_005da480(ushort *param_1,byte *param_2,char *param_3,float param_4)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar6 = (uint)*param_2;
  uVar8 = (uint)*param_1;
  if (uVar8 <= uVar6) {
    uVar6 = uVar8 - 1;
  }
  if ((int)uVar6 < 0) {
    uVar6 = 0;
  }
  fVar2 = *(float *)(*(int *)(param_1 + 2) + uVar6 * 4);
  cVar3 = *(char *)(*(int *)(param_1 + 4) + uVar6);
  iVar7 = *(int *)(param_1 + 2) + uVar6 * 4;
  if (fVar2 < param_4 == (fVar2 == param_4)) {
    do {
      if ((int)uVar6 < 1) break;
      pfVar1 = (float *)(iVar7 + -4);
      iVar7 = iVar7 + -4;
      uVar6 = uVar6 - 1;
    } while (*pfVar1 < param_4 == (*pfVar1 == param_4));
  }
  else {
    uVar5 = uVar6;
    do {
      uVar6 = uVar5;
      if ((int)(uVar8 - 1) <= (int)uVar6) break;
      pfVar1 = (float *)(iVar7 + 4);
      iVar7 = iVar7 + 4;
      uVar5 = uVar6 + 1;
    } while (*pfVar1 <= param_4);
  }
  cVar4 = *(char *)(*(int *)(param_1 + 4) + uVar6);
  *param_3 = cVar4;
  *param_2 = (byte)uVar6;
  return cVar3 != cVar4;
}

