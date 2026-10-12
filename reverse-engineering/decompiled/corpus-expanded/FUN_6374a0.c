/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x6374a0; label: FUN_006374a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006374a0(float param_1)

{
  float fVar1;
  float fVar2;
  int unaff_ESI;
  float10 fVar3;
  float local_8;
  
  if ((*(char *)(unaff_ESI + 0x79) != -1) && (*(char *)(unaff_ESI + 0x7a) == -1)) {
    FUN_006372b0();
  }
  switch(*(undefined1 *)(unaff_ESI + 0x58)) {
  case 0:
    goto switchD_006374c5_caseD_0;
  default:
    *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x24);
    *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x28);
    *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x2c);
    break;
  case 3:
    fVar1 = *(float *)(unaff_ESI + 0x54);
    if (NAN(fVar1) || 0.0 < fVar1 == (fVar1 == 0.0)) {
      param_1 = *(float *)(unaff_ESI + 0x54) + param_1;
      *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x30);
      *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x34);
      *(float *)(unaff_ESI + 0x54) = param_1;
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x38);
      if (0.0 <= param_1) {
        fVar3 = (float10)FUN_005b9dd0();
        *(float *)(unaff_ESI + 0x54) =
             (float)(fVar3 * (float10)*(float *)(unaff_ESI + 0x48) +
                    (float10)*(float *)(unaff_ESI + 0x44));
      }
    }
    else {
      param_1 = *(float *)(unaff_ESI + 0x54) - param_1;
      *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x24);
      *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x28);
      *(float *)(unaff_ESI + 0x54) = param_1;
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x2c);
      if (param_1 < 0.0 != (param_1 == 0.0)) {
        fVar1 = *(float *)(unaff_ESI + 0x4c);
        fVar3 = (float10)FUN_005b9dd0();
        *(float *)(unaff_ESI + 0x54) =
             (float)((float10)-fVar1 - fVar3 * (float10)*(float *)(unaff_ESI + 0x50));
      }
    }
    break;
  case 6:
    if (*(float *)(unaff_ESI + 100) == 0.0) {
      *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x24);
      *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x28);
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x2c);
    }
    else if (*(float *)(unaff_ESI + 100) <= 0.0) {
      param_1 = *(float *)(unaff_ESI + 0x54) - param_1;
      *(float *)(unaff_ESI + 0x54) = param_1;
      fVar1 = 1.0;
      if (((param_1 / *(float *)(unaff_ESI + 100) < 0.0) ||
          (param_1 / *(float *)(unaff_ESI + 100) <= 1.0)) &&
         (fVar1 = *(float *)(unaff_ESI + 0x54) / *(float *)(unaff_ESI + 100), fVar1 < 0.0)) {
        fVar1 = 0.0;
      }
      fVar2 = 1.0 - fVar1;
      *(float *)(unaff_ESI + 0x18) =
           *(float *)(unaff_ESI + 0x24) * fVar2 + *(float *)(unaff_ESI + 0x30) * fVar1;
      *(float *)(unaff_ESI + 0x1c) =
           *(float *)(unaff_ESI + 0x28) * fVar2 + *(float *)(unaff_ESI + 0x34) * fVar1;
      *(float *)(unaff_ESI + 0x20) =
           fVar1 * *(float *)(unaff_ESI + 0x38) + *(float *)(unaff_ESI + 0x2c) * fVar2;
      if (*(float *)(unaff_ESI + 0x54) <= *(float *)(unaff_ESI + 100)) {
        fVar3 = (float10)FUN_005b9dd0();
        *(float *)(unaff_ESI + 100) =
             (float)(fVar3 * (float10)*(float *)(unaff_ESI + 0x48) +
                    (float10)*(float *)(unaff_ESI + 0x44));
        *(undefined4 *)(unaff_ESI + 0x54) = 0;
      }
    }
    else {
      param_1 = *(float *)(unaff_ESI + 0x54) + param_1;
      *(float *)(unaff_ESI + 0x54) = param_1;
      fVar1 = 1.0;
      if (((param_1 / *(float *)(unaff_ESI + 100) < 0.0) ||
          (param_1 / *(float *)(unaff_ESI + 100) <= 1.0)) &&
         (fVar1 = *(float *)(unaff_ESI + 0x54) / *(float *)(unaff_ESI + 100), fVar1 < 0.0)) {
        fVar1 = 0.0;
      }
      fVar2 = 1.0 - fVar1;
      *(float *)(unaff_ESI + 0x18) =
           *(float *)(unaff_ESI + 0x30) * fVar2 + *(float *)(unaff_ESI + 0x24) * fVar1;
      *(float *)(unaff_ESI + 0x1c) =
           *(float *)(unaff_ESI + 0x34) * fVar2 + *(float *)(unaff_ESI + 0x28) * fVar1;
      *(float *)(unaff_ESI + 0x20) =
           fVar1 * *(float *)(unaff_ESI + 0x2c) + *(float *)(unaff_ESI + 0x38) * fVar2;
      if (*(float *)(unaff_ESI + 100) < *(float *)(unaff_ESI + 0x54) !=
          (*(float *)(unaff_ESI + 100) == *(float *)(unaff_ESI + 0x54))) {
        fVar1 = *(float *)(unaff_ESI + 0x4c);
        fVar3 = (float10)FUN_005b9dd0();
        *(float *)(unaff_ESI + 100) =
             (float)((float10)-fVar1 - fVar3 * (float10)*(float *)(unaff_ESI + 0x50));
        *(undefined4 *)(unaff_ESI + 0x54) = 0;
      }
    }
    break;
  case 8:
    fVar1 = 1.0 - *(float *)(unaff_ESI + 0x74);
    *(float *)(unaff_ESI + 0x18) =
         *(float *)(unaff_ESI + 0x24) * fVar1 +
         *(float *)(unaff_ESI + 0x30) * *(float *)(unaff_ESI + 0x74);
    *(float *)(unaff_ESI + 0x1c) =
         *(float *)(unaff_ESI + 0x28) * fVar1 +
         *(float *)(unaff_ESI + 0x34) * *(float *)(unaff_ESI + 0x74);
    *(float *)(unaff_ESI + 0x20) =
         *(float *)(unaff_ESI + 0x38) * *(float *)(unaff_ESI + 0x74) +
         *(float *)(unaff_ESI + 0x2c) * fVar1;
    fVar2 = *(float *)(unaff_ESI + 0x74) + param_1 * *(float *)(unaff_ESI + 0x70);
    *(float *)(unaff_ESI + 0x74) = fVar2;
    fVar1 = 1.0;
    local_8 = fVar2;
    if (1.0 < fVar2) {
      local_8 = 1.0;
    }
    if (0.0 <= local_8) {
      if (fVar2 <= 1.0) {
        fVar1 = *(float *)(unaff_ESI + 0x74);
      }
    }
    else {
      local_8 = 0.0;
      fVar1 = local_8;
    }
    *(float *)(unaff_ESI + 0x74) = fVar1;
    param_1 = *(float *)(unaff_ESI + 0x54) - param_1;
    *(float *)(unaff_ESI + 0x54) = param_1;
    if (param_1 < 0.0 != (param_1 == 0.0)) {
      *(undefined4 *)(unaff_ESI + 0x54) = *(undefined4 *)(unaff_ESI + 0x4c);
      fVar1 = *(float *)(unaff_ESI + 0x70);
      if (NAN(fVar1) || 0.0 < fVar1 == (fVar1 == 0.0)) {
        fVar3 = (float10)FUN_005b9dd0();
        *(float *)(unaff_ESI + 0x70) =
             (float)(fVar3 * (float10)*(float *)(unaff_ESI + 0x48) +
                    (float10)*(float *)(unaff_ESI + 0x44));
      }
      else {
        fVar3 = (float10)FUN_005b9dd0();
        *(float *)(unaff_ESI + 0x70) =
             (float)-(fVar3 * (float10)*(float *)(unaff_ESI + 0x48) +
                     (float10)*(float *)(unaff_ESI + 0x44));
      }
    }
  }
  if ((*(char *)(unaff_ESI + 0x79) == -1) && (*(char *)(unaff_ESI + 0x7a) == -1)) {
    FUN_00637450();
    return;
  }
switchD_006374c5_caseD_0:
  return;
}

