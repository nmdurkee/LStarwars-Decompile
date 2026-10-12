/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x466b30; label: FUN_00466b30
 */

void FUN_00466b30(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  if (in_ECX != 0) {
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    if ((*(byte *)(in_ECX + 0x74) & 0x40) != 0) {
      for (puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x28) + 0x18); puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        iVar2 = FUN_005cfa50(puVar1 + 1);
        if (iVar2 != 0) {
          _memset(local_44,0,0x40);
          iVar2 = FUN_00466af0(0x40);
          if (iVar2 != 0) {
            FUN_004f1e80(local_44,&DAT_00758b40);
            iVar2 = FUN_005cf5b0(puVar1[1],(undefined4 *)(in_ECX + 0x2c),local_44,1);
            if (iVar2 != 0) break;
          }
        }
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

