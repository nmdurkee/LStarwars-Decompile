/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x70284f; label: HeapManager::Destructor
 */

/* Library Function - Single Match
    public: void __thiscall HeapManager::Destructor(void)
   
   Library: Visual Studio 2005 Release */

void __thiscall HeapManager::Destructor(HeapManager *this)

{
  if (*(int *)(this + 4) != 0) {
    while (*(int *)(this + 0xc) = *(int *)(this + 8), *(int *)(this + 8) != 0) {
      *(undefined4 *)(this + 8) = **(undefined4 **)(this + 0xc);
      (**(code **)(this + 4))(*(undefined4 *)(this + 0xc));
    }
  }
  return;
}

