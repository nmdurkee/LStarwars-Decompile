/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c2da0; label: FUN_006c2da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2da0(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (((param_2 != 0) && (uVar1 = *(uint *)(param_2 + 0xc) >> 6, uVar1 < 10)) &&
     (uVar1 * 0xa8 != -0x2973e9c)) {
    DAT_02974644 = 0xffff;
    uVar2 = (&DAT_02973f40)[uVar1 * 0x2a];
    uVar2 = (((int)(uVar2 << 0x1e) >> 0x1f) * -2 - 1U ^ uVar2) & 2 ^ uVar2;
    (&DAT_02973f40)[uVar1 * 0x2a] = uVar2;
    *(byte *)(param_2 + 0x11) =
         *(byte *)(param_2 + 0x11) ^
         ((byte)((int)(uVar2 << 0x1e) >> 0x1f) ^ *(byte *)(param_2 + 0x11)) & 1;
  }
  return;
}

