/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5f9fa0; label: FUN_005f9fa0
 */

void FUN_005f9fa0(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined1 local_40 [64];
  
  if ((((DAT_008264c4 != '\0') && (DAT_008264bc == 1)) &&
      (puVar2 = *(undefined4 **)(param_1 + 0x19c), puVar2 != (undefined4 *)0x0)) &&
     (*(char *)(param_1 + 0x1a0) == '\0')) {
    cVar1 = *(char *)((int)puVar2 + 0xf);
    while (cVar1 != -1) {
      if ((DAT_00973fe8 < 0x118) && (DAT_0080babc != 0)) {
        FUN_005c0500(local_40,(uint)*(byte *)((int)puVar2 + 0xf) * 0x40 + param_3,param_2);
        FUN_005f9ed0(local_40,*puVar2,*(undefined1 *)(puVar2 + 3),puVar2[1],
                     *(undefined1 *)((int)puVar2 + 0xd),puVar2[2],*(undefined1 *)((int)puVar2 + 0xe)
                    );
        DAT_009718a4 = 1;
      }
      cVar1 = *(char *)((int)puVar2 + 0x1f);
      puVar2 = puVar2 + 4;
    }
  }
  return;
}

