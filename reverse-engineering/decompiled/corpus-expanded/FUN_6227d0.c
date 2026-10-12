/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x6227d0; label: FUN_006227d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006227d0(void)

{
  int iVar1;
  undefined1 *puVar2;
  float10 fVar3;
  float local_4c;
  float local_48;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_4c;
  puVar2 = &DAT_02900c88;
  local_4c = 0.0;
  if (&DAT_02900c88 < PTR_DAT_0080fac8) {
    do {
      FUN_005eaad0(DAT_009738b8,0x3f800000,0x3f800000);
      fVar3 = (float10)FUN_005d0d60(DAT_009738b8,puVar2 + 7);
      local_48 = (float)fVar3;
      if (puVar2[6] != '#') {
        FUN_005eaad0(DAT_009738b8,0x3f4ccccd,0x3f800000);
        FUN_004f2740(local_44," %.2d/%.2d/%d %.2d:%.2d:%.2d",(byte)puVar2[4] - 0x41,
                     (byte)puVar2[5] - 0x41,(byte)puVar2[6] + 0x77b,(byte)puVar2[3] - 0x41,
                     (byte)puVar2[2] - 0x41,(byte)puVar2[1] - 0x41);
        fVar3 = (float10)FUN_005d0d60(DAT_009738b8,local_44);
        local_48 = (float)(fVar3 + (float10)local_48);
      }
      if (local_4c < local_48) {
        local_4c = local_48;
      }
      iVar1 = FUN_004f1ff0(puVar2 + 7);
      puVar2 = puVar2 + iVar1 + 8;
    } while (puVar2 < PTR_DAT_0080fac8);
  }
  __security_check_cookie(local_4 ^ (uint)&local_4c);
  return;
}

