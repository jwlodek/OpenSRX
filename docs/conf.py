# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

import subprocess
import os

# -- Run Doxygen automatically when building docs ----------------------------

read_the_docs_build = os.environ.get("READTHEDOCS", None) == "True"

def run_doxygen(_):
    """Run Doxygen before Sphinx so Breathe has XML to consume."""
    subprocess.check_call(["doxygen", "Doxyfile"], cwd=os.path.dirname(__file__))

def setup(app):
    app.connect("builder-inited", run_doxygen)


# -- Project information -----------------------------------------------------

project = "OpenSRX"
copyright = "2025, Jakub Wlodek"
author = "Jakub Wlodek"
release = "0.1.0"

# -- General configuration ---------------------------------------------------

extensions = [
    "breathe",
    "sphinx.ext.autodoc",
    "sphinx.ext.viewcode",
]

templates_path = ["_templates"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]

# -- Breathe configuration ---------------------------------------------------

breathe_projects = {
    "OpenSRX": "_build/doxygen/xml",
}
breathe_default_project = "OpenSRX"
breathe_default_members = ("members", "undoc-members")

# -- Options for HTML output -------------------------------------------------

html_theme = "sphinx_rtd_theme"
html_static_path = ["_static"]
