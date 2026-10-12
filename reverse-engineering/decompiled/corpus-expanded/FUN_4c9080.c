/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c9080; label: FUN_004c9080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c9080(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 local_24;
  undefined4 local_23;
  undefined4 local_1f;
  undefined1 local_1b;
  undefined4 local_18 [5];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_24;
  iVar1 = 0;
  local_24 = 0;
  local_23 = 0;
  local_1f = 0;
  local_1b = 0;
  if (DAT_00951b50 == 0) {
    if ((((DAT_0087aa5c == 0) || (DAT_0087aa60 == 0)) || (DAT_0087aa68 == 0)) ||
       ((*(float *)(DAT_0087aa68 + 0x28) != 1.0 || (*(float *)(DAT_0087aa5c + 0x28) <= 0.0))))
    goto LAB_004c91c2;
    uVar2 = FUN_006e6b90();
    if (10 < (int)uVar2) {
      uVar2 = 10;
    }
    iVar1 = FUN_006e6b90();
    iVar4 = 0;
    if (0 < (int)uVar2) {
      puVar5 = local_18;
      for (uVar3 = uVar2 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = CONCAT22(DAT_007f1948,DAT_007f1948);
        puVar5 = puVar5 + 1;
      }
      for (uVar3 = (uint)((uVar2 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined2 *)puVar5 = DAT_007f1948;
        puVar5 = (undefined4 *)((int)puVar5 + 2);
      }
      do {
        if ((int)(uVar2 - iVar1) <= iVar4) {
          (&local_24)[iVar4] = 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)uVar2);
    }
  }
  else {
    if (((DAT_00880548 == 0) || (*(char *)(DAT_00880548 + 4) != '\x01')) ||
       (*(char *)(DAT_00880548 + 1) == '\0')) goto LAB_004c91c2;
    if (*(char *)(DAT_00880548 + 1) != '\0') {
      do {
        *(undefined2 *)((int)local_18 + iVar1 * 2) = DAT_007f1948;
        if ((int)((uint)*(byte *)(DAT_00880548 + 1) - (uint)*(byte *)(DAT_00880548 + 2)) <= iVar1) {
          (&local_24)[iVar1] = 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)(uint)*(byte *)(DAT_00880548 + 1));
    }
    uVar2 = (uint)*(byte *)(DAT_00880548 + 1);
  }
  FUN_004ba2e0(local_18,&local_24,uVar2);
LAB_004c91c2:
  __security_check_cookie(local_4 ^ (uint)&local_24);
  return;
}

