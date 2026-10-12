/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x615140; label: FUN_00615140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00615140(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int in_ECX;
  uint local_14;
  undefined1 local_10 [4];
  int local_c;
  int local_4;
  
  if (param_1 != 0) {
    if (param_3 == 0) {
      iVar1 = FUN_00612b60(param_1);
    }
    else {
      if (*(int *)(in_ECX + 0x3c + param_3 * 0x18) == 0) {
        return 1;
      }
      iVar1 = in_ECX + (param_3 * 3 + 6) * 8;
    }
    if (iVar1 != 0) {
      FUN_00612b10(iVar1);
      if (*(int *)(in_ECX + 0xc) != 0) {
        param_3 = (uint)*(ushort *)(iVar1 + 2);
        local_14 = FUN_006be780(*(undefined4 *)(iVar1 + 0x10));
        local_14 = local_14 & 0xffff;
        FUN_0053d5d0(0x20);
        param_1 = CONCAT31(param_1._1_3_,6);
        if (local_c != 0) {
          FUN_004ef660(local_4 + local_c,&param_1,1);
          local_4 = local_4 + 1;
        }
        FUN_00613100(&param_3);
        FUN_00613100(&local_14);
        FUN_0053d460(local_10);
        FUN_0060f190();
        if (local_c != 0) {
          if (1 < *(uint *)(local_c + 0x4b0)) {
            *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
            FUN_00611e60();
            return 1;
          }
          *(undefined4 *)(local_c + 0x4b0) = 0;
        }
      }
      FUN_00611e60();
    }
  }
  return 1;
}

