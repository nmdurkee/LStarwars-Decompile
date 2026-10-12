/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x570280; label: FUN_00570280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00570280(int param_1)

{
  float *pfVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  float fVar5;
  bool bVar6;
  bool bVar7;
  float fVar8;
  int in_EAX;
  int iVar9;
  int iVar10;
  int *piVar11;
  int unaff_EDI;
  float10 fVar12;
  float fStack_1c;
  float local_10;
  float fStack_c;
  
  iVar10 = 0;
  if (in_EAX == 0) {
    return 0;
  }
  if (((*(uint *)(*(int *)(unaff_EDI + 0x54) + 4) & 0x2000) == 0) || (DAT_00951288 == 0)) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  local_10 = 0.0;
  if (DAT_00950f78 != (code *)0x0) {
    fVar12 = (float10)(*DAT_00950f78)();
    local_10 = (float)fVar12;
    if (local_10 != 0.0) {
      bVar7 = true;
    }
  }
  iVar9 = FUN_0056e0f0(0x8000);
  fVar8 = DAT_00950f60;
  if ((iVar9 != 0) || (bVar6 = false, 0.0 < *(float *)(unaff_EDI + 0xdec))) {
    bVar6 = true;
  }
  fStack_1c = DAT_00950f60;
  if (bVar6) {
    fStack_1c = _DAT_008033ac * DAT_00950f60;
  }
  if (local_10 != 0.0) {
    fStack_1c = local_10 * fStack_1c;
  }
  if ((bVar7) && (DAT_00951288 != 0)) {
    fStack_1c = fStack_1c + fStack_1c;
  }
  piVar11 = (int *)PTR_PTR_008033b0;
  if (0 < param_1) {
    do {
      iVar4 = *piVar11;
      iVar9 = iVar4 + (uint)*(byte *)(in_EAX + 0x25) * 0x38;
      if ((((((*(byte *)(iVar4 + 0xe + (uint)*(byte *)(in_EAX + 0x25) * 0x38) & 0x10) == 0) &&
            (bVar3 = *(byte *)(in_EAX + 0x17), (bVar3 & 1) != 0)) && ((bVar3 & 8) == 0)) &&
          ((bVar3 & 2) != 0)) && (((bVar3 & 0x10) != 0 || ((*(byte *)(in_EAX + 0x15) & 4) != 0)))) {
        if (((bVar3 & 0x40) != 0) && ((char)piVar11[3] != -1)) {
          iVar9 = iVar4 + (char)piVar11[3] * 0x38;
        }
        if (*(char *)(iVar9 + 0xf) == '\0') {
          if ((*(byte *)(in_EAX + 0x15) & 4) != 0) {
            return in_EAX;
          }
          if (*(short *)(iVar9 + 0x12) == 0) {
            fStack_c = *(float *)(iVar9 + 0x30) * fVar8;
            if (bVar6) {
              fVar2 = *(float *)(iVar9 + 0x34);
            }
            else {
              fVar2 = *(float *)(iVar9 + 0x18);
            }
            fVar2 = fVar2 * fVar8;
          }
          else {
            fStack_c = *(float *)(iVar9 + 0x30) * fStack_1c;
            if (bVar6) {
              fVar2 = *(float *)(iVar9 + 0x34) * fStack_1c;
            }
            else {
              fVar2 = *(float *)(iVar9 + 0x18) * fStack_1c;
            }
          }
          pfVar1 = (float *)(in_EAX + 8);
          if (((*(float *)(unaff_EDI + 0x178) <= fStack_c + *pfVar1) &&
              (*pfVar1 - fStack_c <= *(float *)(unaff_EDI + 0x184))) &&
             ((*(float *)(unaff_EDI + 0x180) <= fStack_c + *(float *)(in_EAX + 0x10) &&
              (*(float *)(in_EAX + 0x10) - fStack_c <= *(float *)(unaff_EDI + 0x18c))))) {
            if (bVar7) {
LAB_0057053a:
              fVar2 = *pfVar1 - *(float *)(unaff_EDI + 0x80);
              fVar5 = *(float *)(in_EAX + 0x10) - *(float *)(unaff_EDI + 0x88);
              fStack_c = fStack_c + *(float *)(unaff_EDI + 0x1dc);
              fVar2 = fVar2 * fVar2 + fVar5 * fVar5;
              fStack_c = fStack_c * fStack_c;
              if (fStack_c < fVar2 == (fStack_c == fVar2)) {
                return in_EAX;
              }
            }
            else if ((*(float *)(unaff_EDI + 0x17c) <= fVar2 + *(float *)(in_EAX + 0xc)) &&
                    (*(float *)(in_EAX + 0xc) - fVar2 <= *(float *)(unaff_EDI + 0x188))) {
              if (*(int *)(unaff_EDI + 0xcd0) != 0) goto LAB_0057053a;
              iVar9 = FUN_0054fce0(pfVar1,fStack_c,fVar2,unaff_EDI + 0x80,
                                   *(undefined4 *)(unaff_EDI + 0xac),
                                   *(undefined4 *)(unaff_EDI + 0x1e0));
              piVar11 = (int *)PTR_PTR_008033b0;
              if (iVar9 != 0) {
                return in_EAX;
              }
            }
          }
        }
      }
      iVar10 = iVar10 + 1;
      in_EAX = in_EAX + 0x2c;
    } while (iVar10 < param_1);
  }
  return 0;
}

