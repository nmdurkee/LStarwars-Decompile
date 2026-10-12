/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x690e40; label: FUN_00690e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00690e40(float param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_c;
  float local_8;
  float local_4;
  
  if ((DAT_02921884 == -1) ||
     (FUN_005b3800(&local_c,&DAT_02961ff0,DAT_02921884 * 0x50 + 8 + DAT_02962a14),
     local_4 * local_4 + local_c * local_c + local_8 * local_8 != 0.0)) {
    iVar2 = 0;
    DAT_02921884 = -1;
    if (0 < DAT_02962a08) {
      iVar3 = 0;
      do {
        if (*(int *)(iVar3 + 4 + DAT_02962a14) != 0) {
          FUN_005b3800(&local_c,&DAT_02961ff0,iVar3 + 8 + DAT_02962a14);
          fVar1 = local_4 * local_4 + local_c * local_c + local_8 * local_8;
          if ((param_1 < 0.0) || (fVar1 < param_1)) {
            DAT_02921884 = iVar2;
            param_1 = fVar1;
          }
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x50;
      } while (iVar2 < DAT_02962a08);
      if (DAT_02921884 != -1) {
        FUN_00690d40(DAT_02921884);
      }
    }
  }
  return;
}

