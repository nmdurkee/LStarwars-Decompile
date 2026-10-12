/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b12a0; label: FUN_005b12a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b12a0(void)

{
  int iVar1;
  int in_ECX;
  
  if ((0.0 < *(float *)(*(int *)(in_ECX + 4) + 4)) && (DAT_009506fc != 0)) {
    FUN_006e6b90(DAT_00950704);
    iVar1 = FUN_006e6b90();
    FUN_005db880(0,0,0x2800,0xe00,iVar1 << 0x18);
  }
  return;
}

