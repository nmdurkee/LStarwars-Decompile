/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x690520; label: FUN_00690520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00690520(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = DAT_00810be0;
  DAT_02962b4c = DAT_02962b4c + 1;
  if (5 < DAT_02962b4c) {
    DAT_02962b4c = 0;
    if ((*(int *)(DAT_0296209c + DAT_00810be0 * 4) != 0) &&
       (iVar1 = *(int *)(DAT_0296209c + DAT_00810be0 * 4), *(int *)(iVar1 + 0x2a8) != 0)) {
      fVar2 = _DAT_0296205c;
      if (*(char *)(iVar1 + 0x2f1) == '\x04') {
        fVar2 = _DAT_02962060;
      }
      if (*(float *)(iVar1 + 0x2ac) + 5.0 < fVar2) {
        DAT_02924b44 = DAT_02924b44 + -1;
        *(undefined4 *)(DAT_02962090 + DAT_02924b44 * 4) =
             *(undefined4 *)(*(int *)(DAT_0296209c + DAT_00810be0 * 4) + 0x2a8);
        *(undefined4 *)(*(int *)(DAT_0296209c + iVar3 * 4) + 0x2a8) = 0;
        if (*(float *)(*(int *)(DAT_0296209c + iVar3 * 4) + 0x420) != 1.0) {
          FUN_0068cdb0(iVar3);
          iVar3 = DAT_00810be0;
        }
      }
    }
    DAT_00810be0 = iVar3 + 1;
    if (DAT_02962098 <= DAT_00810be0) {
      DAT_00810be0 = 1;
    }
  }
  return;
}

