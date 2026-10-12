/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c7a90; label: FUN_004c7a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c7a90(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  int unaff_ESI;
  
  bVar1 = *(byte *)(unaff_ESI + 0x6a);
  bVar2 = (param_1 != 0 ^ bVar1) & 1 ^ bVar1;
  *(byte *)(unaff_ESI + 0x6a) = bVar2;
  bVar2 = bVar2 & 1;
  if ((bVar2 == 0) || ((bVar1 & 1) != 0)) {
    if ((bVar2 == 0) && ((bVar1 & 1) != 0)) {
      FUN_0067c930();
      return;
    }
  }
  else {
    uVar3 = FUN_0067c4f0(unaff_ESI + 0x10,2);
    *(undefined2 *)(unaff_ESI + 0x90) = uVar3;
  }
  return;
}

