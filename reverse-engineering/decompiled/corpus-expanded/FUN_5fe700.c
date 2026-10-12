/* Ghidra pseudocode, not original source.
 * ev_89ac6cdcf79c80fd66b36aa582044170c8ea90809525d25928dfed7b186ac36e
 * Entry: 0x5fe700; label: FUN_005fe700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005fe7a2) */

void FUN_005fe700(short param_1)

{
  float fVar1;
  short sVar2;
  short *psVar3;
  int local_8;
  
  psVar3 = &DAT_00981cc0;
  do {
    if (*psVar3 != 0) {
      sVar2 = *psVar3 - param_1;
      *psVar3 = sVar2;
      if (sVar2 < 1) {
        *psVar3 = 0;
      }
      else {
        fVar1 = (float)(int)sVar2 / (float)(int)psVar3[1];
        *(float *)(psVar3 + -6) =
             *(float *)(psVar3 + -8) + fVar1 * (*(float *)(psVar3 + -10) - *(float *)(psVar3 + -8));
        if (fVar1 <= 0.75) {
          fVar1 = fVar1 * 1.3333334;
        }
        else {
          fVar1 = (1.0 - fVar1) * 4.0;
        }
        local_8 = (int)(longlong)ROUND((float)(*(uint *)(psVar3 + -4) >> 0x18) * fVar1);
        *(uint *)(psVar3 + -2) = local_8 * 0x1000000 + (*(uint *)(psVar3 + -4) & 0xffffff);
      }
    }
    psVar3 = psVar3 + 0x14;
  } while ((int)psVar3 < 0x9821c0);
  return;
}

