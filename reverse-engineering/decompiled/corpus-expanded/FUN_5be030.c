/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5be030; label: FUN_005be030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short FUN_005be030(float param_1,float param_2)

{
  int iVar1;
  
  if (param_2 < param_1) {
    iVar1 = FUN_006e6b90();
    return 0x4000 - *(short *)(&DAT_008066c8 + iVar1 * 2);
  }
  iVar1 = FUN_006e6b90();
  return *(short *)(&DAT_008066c8 + iVar1 * 2);
}

