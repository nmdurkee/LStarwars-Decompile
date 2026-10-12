/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635970; label: FUN_00635970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_00635970(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    iVar2 = FUN_00547560(_DAT_02913970,param_1);
    if (iVar2 != 0) {
      bVar1 = *(byte *)(iVar2 + 0x59);
      *(byte *)(iVar2 + 0x59) = (param_2 == 0 ^ bVar1) & 1 ^ bVar1;
      return ~bVar1 & 1;
    }
  }
  return 0;
}

