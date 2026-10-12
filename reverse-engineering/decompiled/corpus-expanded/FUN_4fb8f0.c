/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fb8f0; label: FUN_004fb8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004fb8f0(undefined4 param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  int local_4;
  
  local_4 = 0;
  lVar4 = FUN_004f6d10(param_1);
  uVar2 = param_2;
  uVar3 = (int)param_2 >> 0x1f;
  if ((param_2 & (uint)lVar4) != 0 || (uVar3 & (uint)((ulonglong)lVar4 >> 0x20)) != 0) {
    do {
      lVar1 = lVar4 + 1;
      lVar4 = lVar4 + 1;
      local_4 = local_4 + 1;
      param_2 = param_2 & 0xffffff00;
      FUN_004fb550(param_1,&param_2,1);
    } while ((uVar2 & (uint)lVar1) != 0 || (uVar3 & (uint)((ulonglong)lVar1 >> 0x20)) != 0);
  }
  return local_4;
}

