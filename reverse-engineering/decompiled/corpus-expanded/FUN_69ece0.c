/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69ece0; label: FUN_0069ece0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined8 FUN_0069ece0(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  uVar2 = *(uint *)(iVar1 + 10);
  return CONCAT44((((uint)*(byte *)(iVar1 + 0xd) << 8 | (uVar2 & 0xffffff) >> 0x10) << 8 |
                  (uVar2 & 0xffff) >> 8) << 8 | (uint)*(byte *)(iVar1 + 10),
                  *(undefined4 *)(iVar1 + 6));
}

