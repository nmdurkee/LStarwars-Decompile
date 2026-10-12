/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x690d40; label: FUN_00690d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00690d40(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 local_c00 [3072];
  
  if ((param_1 != -1) && (param_1 != DAT_00810a8c)) {
    iVar6 = param_1 * 0x50;
    iVar3 = *(int *)(iVar6 + 0x4c + DAT_02962a14);
    if (iVar3 != 0) {
      iVar1 = *(int *)(iVar6 + 4 + DAT_02962a14);
      FUN_004ef660(local_c00,iVar3,iVar1 * 0xc);
      iVar4 = *(int *)(iVar6 + 0x4c + DAT_02962a14);
      iVar3 = iVar4 + *(int *)(iVar6 + 4 + DAT_02962a14) * 0xc;
      FUN_004ef660(iVar4,iVar3,DAT_029629fc - iVar3);
      FUN_004ef660(DAT_029629fc + iVar1 * -0xc,local_c00,iVar1 * 0xc);
      DAT_00810a8c = param_1;
      iVar4 = 0;
      iVar3 = DAT_02962a14;
      if (0 < DAT_02962a08) {
        iVar5 = 0;
        do {
          if ((iVar4 != param_1) && (*(int *)(iVar3 + 4 + iVar5) != 0)) {
            uVar2 = *(uint *)(iVar3 + 0x4c + iVar5);
            if (*(uint *)(iVar6 + 0x4c + iVar3) < uVar2) {
              *(uint *)(iVar3 + 0x4c + iVar5) = uVar2 + iVar1 * -0xc;
              iVar3 = DAT_02962a14;
            }
          }
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0x50;
        } while (iVar4 < DAT_02962a08);
      }
      *(int *)(iVar6 + 0x4c + iVar3) = DAT_029629fc + iVar1 * -0xc;
      FUN_00689f70();
    }
  }
  return;
}

