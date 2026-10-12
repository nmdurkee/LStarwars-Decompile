/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527bc0; label: FUN_00527bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00527bc0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float local_14;
  undefined1 local_c [12];
  
  local_14 = 3.4028235e+38;
  iVar8 = FUN_004f1440(DAT_009238e4 + 0x43814);
  iVar6 = 0;
  fVar7 = local_14;
  while (iVar8 != 0) {
    fVar11 = (float10)FUN_005b3cf0(DAT_009238e4 + 0x28,iVar8 + 8,local_c);
    fVar1 = (float)fVar11;
    iVar10 = iVar6;
    local_14 = fVar7;
    if (fVar1 < fVar7) {
      fVar5 = *(float *)(DAT_009238e4 + 0x2c) - *(float *)(iVar8 + 0xc);
      if (0.2 <= *(float *)(iVar8 + 0x1c)) {
        fVar2 = *(float *)(iVar8 + 0x1c);
      }
      else {
        fVar2 = 0.2;
      }
      if (*(float *)(iVar8 + 0x18) <= -0.2) {
        fVar3 = *(float *)(iVar8 + 0x18);
      }
      else {
        fVar3 = -0.2;
      }
      if (((fVar5 <= fVar2) && (fVar3 < fVar5 != (fVar3 == fVar5))) &&
         (iVar10 = iVar8, local_14 = fVar1, param_1 != 0)) {
        cVar4 = *(char *)(iVar8 + 0x49);
        if (cVar4 == '\0') {
          iVar10 = iVar6;
          local_14 = fVar7;
          if (fVar1 < *(float *)(iVar8 + 0x14) * *(float *)(iVar8 + 0x14)) {
            iVar10 = iVar8;
            local_14 = fVar1;
          }
        }
        else if (cVar4 == '\x01') {
          iVar9 = FUN_00527960();
          iVar10 = iVar6;
          local_14 = fVar7;
          if (iVar9 != 0) {
            iVar10 = iVar8;
            local_14 = fVar1;
          }
        }
        else {
          iVar10 = iVar6;
          local_14 = fVar7;
          if ((cVar4 == '\x02') && (iVar9 = FUN_00527ad0(), iVar9 != 0)) {
            iVar10 = iVar8;
            local_14 = fVar1;
          }
        }
      }
    }
    iVar8 = FUN_004f1460(DAT_009238e4 + 0x43814,iVar8);
    iVar6 = iVar10;
    fVar7 = local_14;
  }
  return iVar6;
}

