/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621a60; label: FUN_00621a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x00621a7a) */

undefined4 FUN_00621a60(undefined4 param_1,undefined4 param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  
  lVar7 = FUN_004fa690(param_1);
  if (lVar7 < 1) {
    return 0;
  }
  iVar3 = FUN_004fa5f0(param_2,1);
  iVar4 = FUN_004fa5f0(param_1,0);
  if (0 < iVar4) {
    if (0 < iVar3) {
      do {
        iVar6 = (int)lVar7;
        iVar5 = iVar6;
        if (0xfff < iVar6) {
          iVar5 = 0x1000;
        }
        FUN_004fb550(iVar4,&DAT_029110b8,iVar5);
        iVar5 = iVar6;
        if (0xfff < iVar6) {
          iVar5 = 0x1000;
        }
        FUN_004f03d0(iVar3,&DAT_029110b8,iVar5);
        lVar2 = lVar7 + -0x1000;
        lVar1 = lVar7 + -0x1000;
        lVar7 = lVar7 + -0x1000;
      } while ((0 < (int)((ulonglong)lVar2 >> 0x20)) ||
              ((-1 < lVar2 && (lVar7 = lVar1, iVar6 != 0x1000))));
      FUN_004f99e0(iVar4);
      FUN_004f99e0(iVar3);
      return 1;
    }
    FUN_004f99e0(iVar4);
  }
  if (0 < iVar3) {
    FUN_004f99e0(iVar3);
  }
  return 0;
}

