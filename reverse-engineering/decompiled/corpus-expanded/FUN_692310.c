/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x692310; label: FUN_00692310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00692310(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (DAT_029231a8 != -1) {
    iVar1 = (&DAT_02924b60)[DAT_029231a8 * 0x16];
    if ((iVar1 != -1) &&
       (iVar1 = *(int *)(DAT_0296209c + *(short *)(iVar1 * 0x330 + 0x182 + DAT_029620a4) * 4),
       (int)*(char *)(iVar1 + 0x2f1) != *(int *)(param_2 + 0xc))) {
      FUN_00684400(&DAT_02924b60 + DAT_029231a8 * 0x16);
      *(undefined1 *)(iVar1 + 0x2f1) = *(undefined1 *)(param_2 + 0xc);
      FUN_0068e6f0(DAT_029231a8);
    }
  }
  return;
}

