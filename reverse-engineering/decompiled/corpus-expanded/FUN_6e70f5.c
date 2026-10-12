/* Ghidra pseudocode, not original source.
 * ev_be0e8c275e05089d0d3721217efe04c64b57d8015b7c05fc7983bdf2d5551943
 * Entry: 0x6e70f5; label: FUN_006e70f5
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006e70f5(undefined4 param_1)

{
  uint uVar1;
  undefined4 *_Memory;
  undefined4 *puVar2;
  size_t sVar3;
  size_t sVar4;
  void *pvVar5;
  undefined4 uVar6;
  
  _Memory = (undefined4 *)FUN_006f01bc(DAT_029a9c54);
  puVar2 = (undefined4 *)FUN_006f01bc(DAT_029a9c50);
  if (_Memory <= puVar2) {
    uVar1 = ((int)puVar2 - (int)_Memory) + 4;
    if (3 < uVar1) {
      sVar3 = __msize(_Memory);
      if (sVar3 < uVar1) {
        sVar4 = 0x800;
        if (sVar3 < 0x800) {
          sVar4 = sVar3;
        }
        if ((sVar4 + sVar3 < sVar3) ||
           (pvVar5 = __realloc_crt(_Memory,sVar4 + sVar3), pvVar5 == (void *)0x0)) {
          if (sVar3 + 0x10 < sVar3) {
            return 0;
          }
          pvVar5 = __realloc_crt(_Memory,sVar3 + 0x10);
          if (pvVar5 == (void *)0x0) {
            return 0;
          }
        }
        puVar2 = (undefined4 *)((int)pvVar5 + ((int)puVar2 - (int)_Memory >> 2) * 4);
        DAT_029a9c54 = FUN_006f0145(pvVar5);
      }
      uVar6 = FUN_006f0145(param_1);
      *puVar2 = uVar6;
      DAT_029a9c50 = FUN_006f0145(puVar2 + 1);
      return param_1;
    }
  }
  return 0;
}

