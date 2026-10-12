/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x615270; label: FUN_00615270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00615270(int param_1)

{
  ushort *puVar1;
  int in_ECX;
  uint local_18;
  uint local_14;
  undefined1 local_10 [4];
  int local_c;
  int local_4;
  
  if ((((param_1 != 0) && (*(int *)(in_ECX + 0x3c + param_1 * 0x18) != 0)) &&
      (puVar1 = (ushort *)(in_ECX + (param_1 * 3 + 6) * 8), puVar1 != (ushort *)0x0)) &&
     (*puVar1 = *puVar1 | 2, *(char *)(*(int *)(puVar1 + 4) + 0xc) != '\0')) {
    FUN_0053d5d0(0x20);
    local_18 = (uint)puVar1[1];
    local_14 = FUN_006be780(*(undefined4 *)(puVar1 + 8));
    local_14 = local_14 & 0xffff;
    param_1 = CONCAT31(param_1._1_3_,0xc);
    if (local_c != 0) {
      FUN_004ef660(local_c + local_4,&param_1,1);
      local_4 = local_4 + 1;
    }
    FUN_00613100(&local_18);
    FUN_00613100(&local_14);
    FUN_0053d460(local_10);
    FUN_0060f190();
    if (local_c != 0) {
      if (1 < *(uint *)(local_c + 0x4b0)) {
        *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
        return;
      }
      *(undefined4 *)(local_c + 0x4b0) = 0;
    }
  }
  return;
}

