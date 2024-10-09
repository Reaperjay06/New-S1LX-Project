//
//  Pip_Boy_interfaceApp.swift
//  Pip-Boy interface
//
//  Created by SA47 on 10/7/24.
//

import SwiftUI

@main
struct Pip_Boy_interfaceApp: App {
    var body: some Scene {
        DocumentGroup(newDocument: Pip_Boy_interfaceDocument()) { file in
            ContentView(document: file.$document)
        }
    }
}
