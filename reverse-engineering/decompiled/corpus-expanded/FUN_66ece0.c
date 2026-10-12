/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66ece0; label: FUN_0066ece0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066ece0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_18;
  
  if ((DAT_02924ab8 != 0) && (iVar4 = 0, 0 < DAT_02924ab8)) {
    iVar3 = 0;
    do {
      puVar1 = (undefined4 *)(iVar3 + 8 + DAT_0292fb50);
      if (iVar4 == DAT_02924ab8) {
        local_18 = *(undefined4 *)(iVar3 + DAT_0292fb50);
        uVar2 = *puVar1;
      }
      else {
        local_18 = *(undefined4 *)(iVar3 + 0x10 + DAT_0292fb50);
        uVar2 = *(undefined4 *)(iVar3 + 0x18 + DAT_0292fb50);
      }
      FUN_005dc050(*(undefined4 *)(iVar3 + DAT_0292fb50),param_1,*puVar1,local_18,param_1,uVar2,
                   0x80808080);
      iVar4 = iVar4 + 2;
      iVar3 = iVar3 + 0x20;
    } while (iVar4 < DAT_02924ab8);
  }
  return;
}

