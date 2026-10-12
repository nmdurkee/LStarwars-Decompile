/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4ab790; label: FUN_004ab790
 */

float10 FUN_004ab790(int param_1)

{
  int iVar1;
  undefined *puVar2;
  float10 fVar3;
  float10 extraout_ST0;
  float local_4;
  
  local_4 = 0.15;
  if ((param_1 == DAT_0093d7f4) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
    fVar3 = (float10)FUN_005b3c50(DAT_0093d7f0 + 0x5c,DAT_0093d7f4 + 0x5c,0);
    if ((float)fVar3 < 4.0) {
      FUN_005c0240((float)fVar3);
      iVar1 = FUN_006e6b90();
      local_4 = (float)(extraout_ST0 * (float10)(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] +
                       (float10)0.15000000596046448);
    }
  }
  if (((DAT_0087af5c != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c)) &&
     ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    puVar2 = &DAT_007fc22c;
    while (fVar3 = (float10)FUN_005b3cf0(param_1 + 0x5c,puVar2,0), (float10)2.0 <= fVar3) {
      puVar2 = puVar2 + 0xc;
      if (0x7fc24f < (int)puVar2) {
        return (float10)local_4;
      }
    }
    local_4 = local_4 + 1.5;
  }
  return (float10)local_4;
}

