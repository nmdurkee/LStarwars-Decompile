/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44e0f0; label: FUN_0044e0f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0044e0f0(int param_1)

{
  int iVar1;
  int iVar2;
  uint in_ECX;
  uint uVar3;
  float *unaff_ESI;
  
  *unaff_ESI = 0.0;
  iVar1 = *(int *)(param_1 + 0x7c);
  while( true ) {
    iVar2 = in_ECX * 0x5c + iVar1;
    if (iVar2 == 0) {
      *unaff_ESI = 1e+09;
      return 0;
    }
    if ((*(byte *)(iVar2 + 0x2b) & 1) != 0) break;
    iVar2 = *(int *)(*(int *)(iVar2 + 0x34) +
                    (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x84) + in_ECX * 4) +
                                   (uint)*(ushort *)(iVar2 + 0x2c)) * 4);
    uVar3 = (uint)*(byte *)(iVar2 + 0x10);
    if (in_ECX == uVar3) {
      uVar3 = (uint)*(byte *)(iVar2 + 0x11);
    }
    *unaff_ESI = *(float *)(iVar2 + 0x18) + *unaff_ESI;
    in_ECX = uVar3;
  }
  return iVar2;
}

