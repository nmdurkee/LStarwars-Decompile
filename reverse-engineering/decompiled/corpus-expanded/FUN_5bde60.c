/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bde60; label: FUN_005bde60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005bde60(void)

{
  ulonglong uVar1;
  uint in_ECX;
  uint unaff_ESI;
  
  if (in_ECX < unaff_ESI) {
    return 0x4000 - (uint)*(ushort *)(&DAT_008066c8 + ((in_ECX << 9) / unaff_ESI) * 2);
  }
  uVar1 = (ulonglong)(unaff_ESI << 9) / (ulonglong)in_ECX;
  return CONCAT22((short)(uVar1 >> 0x10),*(undefined2 *)(&DAT_008066c8 + (int)uVar1 * 2));
}

