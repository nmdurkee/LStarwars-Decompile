/* Ghidra analysis pseudocode, not original source.
 * ev_436cabf158ac3440cfd7f7b18cfc1716350a7e3fc3c1046d0c76060bee472dbc
 * Entry: 0x6e5a30; label: FUN_006e5a30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5a30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14)

{
  _DAT_0297bea0 =
       D3DXCreateTextureFromFileInMemoryEx
                 (DAT_029765cc,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                  param_9,param_10,param_11,param_12,param_13,param_14);
  return;
}

