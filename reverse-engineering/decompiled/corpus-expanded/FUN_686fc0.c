/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x686fc0; label: FUN_00686fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00686fc0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_c [12];
  
  iVar2 = DAT_02947c10;
  if (DAT_02962108 != 0x40) {
    iVar1 = (&DAT_0292fe18)[DAT_02947c10 * 0xb5];
    while( true ) {
      if (iVar1 == -1) {
        DAT_02947c10 = iVar2;
        (&DAT_0292fe18)[iVar2 * 0xb5] = param_1;
        (&DAT_0292fe1c)[iVar2 * 0xb5] = 0;
        FUN_005da860(local_c,DAT_02962114,param_1);
        iVar2 = DAT_02947c10;
        uVar3 = FUN_005cffb0(local_c);
        uVar3 = FUN_0067c760(uVar3);
        (&DAT_029300d8)[iVar2 * 0xb5] = uVar3;
        (&DAT_029300dc)[iVar2 * 0xb5] = 0;
        (&DAT_029300e0)[iVar2 * 0xb5] = 0;
        (&DAT_029300e4)[iVar2 * 0xb5] = 0;
        if ((&DAT_029300d8)[iVar2 * 0xb5] != -1) {
          FUN_0067c7e0((&DAT_029300d8)[iVar2 * 0xb5],(&DAT_029300dc)[iVar2 * 0xb5],
                       (&DAT_029300e0)[iVar2 * 0xb5],0);
        }
        iVar1 = DAT_02962924;
        iVar2 = (&DAT_02947c7c)[DAT_02962924];
        (&DAT_029300e8)[DAT_02947c10 * 0x2d4] = (char)DAT_02962924;
        (&DAT_02961f80)[iVar1] = 1;
        (&DAT_0292fd80)[iVar1] = 1;
        if (iVar2 == 0) {
          (&DAT_02947c7c)[iVar1] = DAT_02962114;
        }
        iVar2 = DAT_02947c10;
        DAT_02962108 = DAT_02962108 + 1;
        DAT_02947c10 = DAT_02947c10 + 1;
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      if (0x40 < iVar2) {
        iVar2 = 0;
      }
      if (iVar2 == DAT_02947c10) break;
      iVar1 = (&DAT_0292fe18)[iVar2 * 0xb5];
    }
  }
  DAT_02947c10 = iVar2;
  return -1;
}

