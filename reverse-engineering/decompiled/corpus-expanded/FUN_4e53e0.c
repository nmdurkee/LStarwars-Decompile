/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e53e0; label: FUN_004e53e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e53e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  if ((DAT_0087a7f0 != 0) && (*DAT_00889638 == '\0')) {
    puVar2 = (undefined4 *)(DAT_0087a7f0 + 0x844);
    puVar3 = local_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005f33b0(&DAT_0087aaf0,local_40);
  }
  if ((DAT_0087a7f4 != 0) && (*DAT_00889638 == '\0')) {
    puVar2 = (undefined4 *)(DAT_0087a7f4 + 0x844);
    puVar3 = local_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005f33b0(&DAT_0087aaf0,local_40);
  }
  return;
}

