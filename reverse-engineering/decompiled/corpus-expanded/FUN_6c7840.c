/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7840; label: FUN_006c7840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c7840(int param_1,int param_2,int param_3)

{
  int in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = (-(uint)(param_1 != 0) & 0xff800000) + 0x80808080;
  FUN_006ba6a0(0);
  puVar1 = *(undefined4 **)(in_ECX + 0x2c);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    do {
      if (puVar2 == (undefined4 *)0x0) break;
      if ((param_2 != 0) || (*(float *)(in_ECX + 0x48) < _DAT_0081fa00)) {
        FUN_006ba7d0(puVar1 + 4,puVar2 + 4,iVar3);
      }
      else {
        FUN_006c0180(puVar1 + 4,puVar1 + 0xc,puVar2 + 4,puVar2 + 8,DAT_02973a70,iVar3);
      }
      bVar4 = puVar2 != (undefined4 *)0x0;
      puVar1 = puVar2;
      puVar2 = (undefined4 *)*puVar2;
    } while (bVar4);
  }
  if ((param_3 != 0) && (_DAT_0081fa00 < *(float *)(in_ECX + 0x48))) {
    FUN_006c74e0();
  }
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  return;
}

