/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x6493d0; label: FUN_006493d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006493d0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_02920970;
  if (DAT_02920970 != 0) {
    if (DAT_02920968 == 0) {
      iVar2 = FUN_006e6b90();
      *(float *)(iVar1 + 0x120) = (float)iVar2;
      return;
    }
    if (DAT_02920968 == 1) {
      iVar2 = FUN_006e6b90();
      *(float *)(iVar1 + 0x124) = (float)iVar2;
    }
  }
  return;
}

