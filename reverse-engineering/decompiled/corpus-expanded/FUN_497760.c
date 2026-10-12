/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x497760; label: FUN_00497760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00497760(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((DAT_00951b50 == 0) || (param_3 == 0)) {
    *(char *)(param_1 + 0x1d) = (char)param_2;
    iVar1 = FUN_0054fa60();
    FUN_0042b6f0((int)(iVar1 + (iVar1 >> 0x1f & 0x7fffU)) >> 0xf);
    if (((&DAT_0093d7f0)[DAT_007f3b14] == 0) ||
       ((*(byte *)((&DAT_0093d7f0)[DAT_007f3b14] + 0x1fc) & 0x80) == 0)) {
      DAT_007f3b14 = (uint)(DAT_007f3b14 == 0);
    }
    DAT_0086e71c = 0;
    FUN_00509830(9,0xffffffff,0xffffffff);
    FUN_00560b40();
    if (param_2 == 3) {
      FUN_00681f40("MK-Panel",0);
    }
  }
  return;
}

