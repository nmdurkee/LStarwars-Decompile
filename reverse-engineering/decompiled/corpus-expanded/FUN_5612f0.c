/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x5612f0; label: FUN_005612f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005612f0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float *pfVar2;
  int local_24;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
  pfVar2 = (float *)&DAT_00947c54;
  local_24 = 0x80;
  do {
    if ((*(char *)(pfVar2 + 0x19) != '\0') && (*(char *)((int)pfVar2 + 0x65) == '\0')) {
      FUN_005d6430(pfVar2 + 3,pfVar2,1,0);
      fVar1 = (pfVar2[2] - param_1[2]) * param_3[2] +
              (*pfVar2 - *param_1) * *param_3 + (pfVar2[1] - param_1[1]) * param_3[1];
      if (fVar1 < 0.0 == (fVar1 == 0.0)) {
        *(undefined1 *)((int)pfVar2 + 0x67) = 0;
        if (((uint)pfVar2[0x11] & 4) != 0) {
          local_18 = *param_2 * pfVar2[8] + *pfVar2;
          local_14 = param_2[1] * pfVar2[8] + pfVar2[1];
          local_10 = param_2[2] * pfVar2[8] + pfVar2[2];
          FUN_005d6430(local_c,&local_18,1,0);
          pfVar2[9] = ABS(pfVar2[3] - local_c[0]) * 0.525;
        }
      }
      else {
        *(undefined1 *)((int)pfVar2 + 0x67) = 1;
      }
      if (((uint)pfVar2[0x11] & 2) == 0) {
        *(undefined1 *)((int)pfVar2 + 0x65) = 1;
      }
      pfVar2[5] = 1.0;
    }
    pfVar2 = pfVar2 + 0x45;
    local_24 = local_24 + -1;
  } while (local_24 != 0);
  return;
}

