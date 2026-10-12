/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68c520; label: FUN_0068c520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068c520(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if ((DAT_02962a38 != 0) && (iVar2 = 0, 0 < DAT_02962a38)) {
    do {
      FUN_005b3800(local_18,&DAT_02924b50 + (&DAT_02924acc)[iVar2] * 0x16,&DAT_02947b3c);
      FUN_005b3620(local_18,local_18,DAT_02962acc);
      FUN_005b37d0(local_c,&DAT_02920abc,local_18);
      iVar1 = FUN_0068bfc0(local_c,(&DAT_02924acc)[iVar2]);
      if (iVar1 != -1) {
        (&DAT_02924b6a)[iVar1 * 0x2c] = (&DAT_02924b6a)[iVar1 * 0x2c] + (short)DAT_02962acc;
        FUN_006846a0((&DAT_02924b60)[iVar1 * 0x16],(&DAT_02924b68)[iVar1 * 0x2c],
                     (&DAT_02924b6a)[iVar1 * 0x2c],(&DAT_02924b6c)[iVar1 * 0x2c]);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_02962a38);
  }
  return;
}

