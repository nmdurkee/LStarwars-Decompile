/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bdf20; label: FUN_005bdf20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005bdf20(void)

{
  uint in_ECX;
  uint unaff_ESI;
  
  if (in_ECX < unaff_ESI) {
    return (float10)((float)(int)(0x4000 - (uint)*(ushort *)
                                                  (&DAT_008066c8 + ((in_ECX << 9) / unaff_ESI) * 2))
                    * 9.58738e-05);
  }
  return (float10)((float)*(ushort *)(&DAT_008066c8 + ((unaff_ESI << 9) / in_ECX) * 2) * 9.58738e-05
                  );
}

