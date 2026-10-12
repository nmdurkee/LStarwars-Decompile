/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60c1c0; label: FUN_0060c1c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0060c1c0(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_0060a0b0();
  puVar1[10] = (uint)param_1;
  uVar2 = FUN_005e5470(puVar1);
  puVar1[0xb] = uVar2;
  if (uVar2 == 0) {
    _DAT_02855354 = (int)(puVar1 + -0xa15414) / 0x30;
    (&DAT_02855350)[_DAT_02855354 >> 3] =
         (&DAT_02855350)[_DAT_02855354 >> 3] & ~('\x01' << ((byte)_DAT_02855354 & 7));
    return 0;
  }
  *puVar1 = (uint)(ushort)param_1[1];
  puVar1[1] = (uint)*(ushort *)((int)param_1 + 6);
  puVar1[6] = 1;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = *param_1;
  return puVar1[0xb];
}

