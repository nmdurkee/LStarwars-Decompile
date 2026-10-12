/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d2060; label: FUN_004d2060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d2060(void)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  *in_ECX = *in_EAX;
  in_ECX[1] = in_EAX[1];
  in_ECX[2] = in_EAX[2];
  in_ECX[3] = in_EAX[3];
  return;
}

