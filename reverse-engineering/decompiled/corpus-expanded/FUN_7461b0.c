/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x7461b0; label: FUN_007461b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007461b0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = (-(uint)((uVar3 & 0x80) != 0) & 0x1021) * 2;
    if ((uVar3 & 0x40) != 0) {
      uVar1 = uVar1 ^ 0x1021;
    }
    uVar1 = uVar1 * 2;
    if ((uVar3 & 0x20) != 0) {
      uVar1 = uVar1 ^ 0x1021;
    }
    uVar1 = uVar1 * 2;
    if ((uVar3 & 0x10) != 0) {
      uVar1 = uVar1 ^ 0x1021;
    }
    uVar2 = uVar1 * 2;
    if (((uVar3 << 0xc ^ uVar1) & 0x8000) != 0) {
      uVar2 = uVar2 ^ 0x1021;
    }
    uVar1 = (uVar2 & 0xffff) * 2;
    if (((uVar3 << 0xd ^ uVar2 & 0xffff) & 0x8000) != 0) {
      uVar1 = uVar1 ^ 0x1021;
    }
    uVar2 = (uVar1 & 0xffff) * 2;
    if (((uVar3 * 0x4000 ^ uVar1 & 0xffff) & 0x8000) != 0) {
      uVar2 = uVar2 ^ 0x1021;
    }
    uVar1 = (uVar2 & 0xffff) * 2;
    if (((uVar3 << 0xf ^ uVar2 & 0xffff) & 0x8000) != 0) {
      uVar1 = uVar1 ^ 0x1021;
    }
    (&DAT_0297d698)[uVar3] = uVar1 & 0xffff;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x100);
  return;
}

