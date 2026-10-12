/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x6922c0; label: FUN_006922c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006922c0(void)

{
  int iVar1;
  undefined1 uVar2;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    uVar2 = FUN_006e6b90();
    *(undefined1 *)(iVar1 + 0x410) = uVar2;
    FUN_0068cfd0();
  }
  return;
}

